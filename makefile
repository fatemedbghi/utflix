CC = g++
FLAGS = -std=c++11
COMPILE_FLAGS = $(FLAGS) -c 

all: a.out

a.out: main.o media_service.o controller.o data_base.o delete_comments.o delete_films.o get_films.o get_followers.o get_notifications.o get_notifications_read.o get_published.o get_purchased.o post_buy.o post_comments.o post_films.o post_followers.o post_login.o post_money.o post_signup.o post_rate.o post_replies.o put_films.o user.o publisher.o film.o comment.o
	$(CC) main.o media_service.o controller.o data_base.o delete_comments.o delete_films.o get_films.o get_followers.o get_notifications.o get_notifications_read.o get_published.o get_purchased.o post_buy.o post_comments.o post_films.o post_followers.o post_login.o post_money.o post_signup.o post_rate.o post_replies.o put_films.o user.o publisher.o film.o comment.o $(FLAGS) -o a.out
	
main.o: main.cpp media_service.h
	$(CC) $(COMPILE_FLAGS) main.cpp

media_service.o: media_service.h media_service.cpp controller.h delete_comments.h delete_films.h get_films.h get_followers.h get_notifications.h get_notifications_read.h get_published.h get_purchased.h post_buy.h post_comments.h post_films.h post_followers.h post_login.h post_money.h post_signup.h post_rate.h post_replies.h put_films.h data_base.h
	$(CC) $(COMPILE_FLAGS) media_service.cpp

controller.o: controller.h controller.cpp exception.h user.h publisher.h data_base.h
	$(CC) $(COMPILE_FLAGS) controller.cpp

delete_comments.o: delete_comments.h delete_comments.cpp controller.h
	$(CC) $(COMPILE_FLAGS) delete_comments.cpp

data_base.o: data_base.h data_base.cpp
	$(CC) $(COMPILE_FLAGS) data_base.cpp

delete_films.o: delete_films.h delete_films.cpp controller.h
	$(CC) $(COMPILE_FLAGS) delete_films.cpp

get_films.o: get_films.h get_films.cpp controller.h
	$(CC) $(COMPILE_FLAGS) get_films.cpp

get_followers.o: get_followers.h get_followers.cpp controller.h
	$(CC) $(COMPILE_FLAGS) get_followers.cpp	

get_notifications.o: get_notifications.h get_notifications.cpp controller.h
	$(CC) $(COMPILE_FLAGS) get_notifications.cpp

get_notifications_read.o: get_notifications_read.h get_notifications_read.cpp controller.h
	$(CC) $(COMPILE_FLAGS) get_notifications_read.cpp

get_published.o: get_published.h get_published.cpp controller.h
	$(CC) $(COMPILE_FLAGS) get_published.cpp

get_purchased.o: get_purchased.h get_purchased.cpp controller.h
	$(CC) $(COMPILE_FLAGS) get_purchased.cpp

post_buy.o: post_buy.h post_buy.cpp controller.h
	$(CC) $(COMPILE_FLAGS) post_buy.cpp

post_comments.o: post_comments.h post_comments.cpp controller.h
	$(CC) $(COMPILE_FLAGS) post_comments.cpp

post_films.o: post_films.h post_films.cpp controller.h
	$(CC) $(COMPILE_FLAGS) post_films.cpp

post_followers.o: post_followers.h post_followers.cpp controller.h
	$(CC) $(COMPILE_FLAGS) post_followers.cpp

post_login.o: post_login.h post_login.cpp controller.h
	$(CC) $(COMPILE_FLAGS) post_login.cpp

post_money.o: post_money.h post_money.cpp controller.h
	$(CC) $(COMPILE_FLAGS) post_money.cpp

post_rate.o: post_rate.h post_rate.cpp controller.h
	$(CC) $(COMPILE_FLAGS) post_rate.cpp

post_replies.o: post_replies.h post_replies.cpp controller.h
	$(CC) $(COMPILE_FLAGS) post_replies.cpp

post_signup.o: post_signup.h post_signup.cpp controller.h
	$(CC) $(COMPILE_FLAGS) post_signup.cpp

put_films.o: put_films.h put_films.cpp controller.h
	$(CC) $(COMPILE_FLAGS) put_films.cpp

user.o: user.h user.cpp film.h
	$(CC) $(COMPILE_FLAGS) user.cpp

publisher.o: publisher.h publisher.cpp user.h
	$(CC) $(COMPILE_FLAGS) publisher.cpp

film.o: film.h film.cpp comment.h
	$(CC) $(COMPILE_FLAGS) film.cpp

comment.o: comment.h comment.cpp
	$(CC) $(COMPILE_FLAGS) comment.cpp

.PHONY: clean

clean:
	rm *.o *.out