all:
		sudo chown $(USER) /var/run/docker.sock
		sudo service nginx stop
		cd srcs && docker-compose up --build
down:
		cd srcs && docker-compose down -v

clean:
		docker system prune -a --volumes -f
		sudo rm -rf /home/epfennig/data/mariadb/*
		sudo rm -rf  /home/epfennig/data/wordpress/*


# domaine name :
#vim /etc/hosts
