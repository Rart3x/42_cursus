NAME = inception
SERVICES = mariadb wordpress nginx

all: build start_services
	@printf "Launch configuration ${NAME}...\n"

build:
	@mkdir -p ~/data/wordpress
	@mkdir -p ~/data/mariadb
	@printf "Building configuration ${NAME}...\n"
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env build

down: stop_services
	@printf "Stopping configuration ${NAME}...\n"
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env down

re: down
	@printf "Rebuild configuration ${NAME}...\n"
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d --build

rm_data:
	@sudo rm -rf ~/data/wordpress
	@sudo rm -rf ~/data/mariadb

clean: down rm_data
	@printf "Cleaning configuration ${NAME}...\n"
	@docker system prune -a

fclean: rm_data
	@printf "Total clean of all configurations docker\n"
	@docker stop $$(docker ps -qa)
	@docker system prune --all --force --volumes
	@docker network prune --force
	@docker volume prune --force

.PHONY: all build down re clean fclean rm_data

start_services:
	@printf "Starting specific services...\n"
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d $(SERVICES)

stop_services:
	@printf "Stopping specific services...\n"
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env stop $(SERVICES)

bonus: adminer

adminer:
	@printf "Building adminer service...\n"
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env build adminer
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d adminer
