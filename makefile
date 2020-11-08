all: clean server.out
admin.o: a7/admin.cpp
	g++ -c a7/admin.cpp
controller.o: a7/controller.cpp
	g++ -c a7/controller.cpp
user.o: a7/user.cpp
	g++ -c a7/user.cpp
publisher.o: a7/publisher.cpp
	g++ -c a7/publisher.cpp
film.o: a7/film.cpp
	g++ -c a7/film.cpp
comment.o: a7/comment.cpp
	g++ -c a7/comment.cpp
data_base.o: a7/data_base.cpp
	g++ -c a7/data_base.cpp
my_server.o: a7/my_server.cpp
	g++ -c a7/my_server.cpp
get_published.o: a7/get_published.cpp
	g++ -c a7/get_published.cpp
get_purchased.o: a7/get_purchased.cpp
	g++ -c a7/get_purchased.cpp
get_available_films.o: a7/get_available_films.cpp
	g++ -c a7/get_available_films.cpp
get_films.o: a7/get_films.cpp
	g++ -c a7/get_films.cpp
post_comments.o: a7/post_comments.cpp
	g++ -c a7/post_comments.cpp
post_films.o: a7/post_films.cpp
	g++ -c a7/post_films.cpp
post_buy.o: a7/post_buy.cpp
	g++ -c a7/post_buy.cpp
post_signup.o: a7/post_signup.cpp
	g++ -c a7/post_signup.cpp
post_login.o: a7/post_login.cpp
	g++ -c a7/post_login.cpp
post_logout.o: a7/post_logout.cpp
	g++ -c a7/post_logout.cpp
post_money.o: a7/post_money.cpp
	g++ -c a7/post_money.cpp
post_rate.o: a7/post_rate.cpp
	g++ -c a7/post_rate.cpp
get_money.o: a7/get_money.cpp
	g++ -c a7/get_money.cpp
delete_films.o: a7/delete_films.cpp
	g++ -c a7/delete_films.cpp
utilities.o: utils/utilities.cpp
	g++ -c utils/utilities.cpp
response.o: utils/response.cpp
	g++ -c utils/response.cpp
request.o: utils/request.cpp
	g++ -c utils/request.cpp
template_parser.o: utils/template_parser.cpp
	g++ -c utils/template_parser.cpp
server.o: server/server.cpp
	g++ -c server/server.cpp
route.o: server/route.cpp
	g++ -c server/route.cpp
main.o: a7/main.cpp
	g++ -c a7/main.cpp
server.out: admin.o controller.o user.o data_base.o publisher.o my_server.o post_signup.o post_login.o post_logout.o post_comments.o film.o comment.o get_published.o get_purchased.o get_available_films.o delete_films.o post_rate.o get_films.o post_films.o post_buy.o post_money.o get_money.o utilities.o response.o request.o template_parser.o server.o route.o main.o
	g++ admin.o controller.o user.o data_base.o publisher.o my_server.o post_signup.o post_login.o post_logout.o post_comments.o film.o comment.o get_published.o get_purchased.o get_available_films.o delete_films.o post_rate.o get_films.o post_films.o post_buy.o post_money.o get_money.o utilities.o response.o request.o template_parser.o server.o route.o main.o
clean:
	rm -f *.o