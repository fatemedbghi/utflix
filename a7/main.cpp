#include "post_signup.h"
#include "post_login.h"
#include "post_logout.h"
#include "post_films.h"
#include "my_server.h"
#include "get_published.h"
#include "get_purchased.h"
#include "get_available_films.h"
#include "post_money.h"
#include "get_money.h"
#include "get_films.h"
#include "delete_films.h"
#include "post_buy.h"
#include "post_rate.h"
#include "post_comments.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  srand(time(NULL));
  try {
    MyServer server(argc > 1 ? atoi(argv[1]) : 5000);
    server.setNotFoundErrPage("static/404.html");
    server.get("/error", new ShowPage("static/404.html"));
    server.get("/admin" , new ShowPage("static/admin.html"));
    server.get("/signup", new ShowPage("static/signup.html"));
    server.get("/signup_error", new ShowPage("static/signup_repasserror.html"));
    server.get("/invalid_username", new ShowPage("static/invalid_username_admin.html"));
    server.post("/signup", new PostSignup());
    server.get("/login", new ShowPage("static/login.html"));
    server.get("/login_error", new ShowPage("static/login_error.html"));
    server.post("/login", new PostLogin());
    server.get("/post_films", new ShowPage("static/post_films.html"));
    server.post("/post_films", new PostFilms());
    server.get("/post_money", new ShowPage("static/post_money.html"));
    server.post("/post_money", new PostMoney());
    server.post("/post_rate", new PostRate());
    server.get("/publisher" , new GetPublished());
    server.get("/user" , new GetAvailableFilms());
    server.get("/userprofile" , new GetPurchased());
    server.get("/get_films" , new GetFilms());
    server.get("/delete_films" , new DeleteFilms());
    server.get("/post_buy" , new PostBuy());
    server.get("/get_money" , new GetMoney());
    server.get("/film_details" , new GetFilms());
    server.post("/post_comments" , new PostComments());
    server.get("/logout", new PostLogout());
    server.get("/home.png", new ShowImage("static/home.png"));
    server.get("/background.png", new ShowImage("static/background.png"));
    server.get("/", new ShowPage("static/home.html"));
    server.run();
  } catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
}