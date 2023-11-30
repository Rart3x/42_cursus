FROM alpine:3.17

EXPOSE 9000

WORKDIR /var/www/html

RUN apk update && apk upgrade && \
	apk add --no-cache php php-fpm php-phar php81-mysqli php81-iconv php81-mbstring mariadb-client && \
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

RUN sed -i '/listen = 127.0.0.1:9000/c listen = wordpress:9000' /etc/php81/php-fpm.d/www.conf

COPY ./conf/wp-install.sh /tmp/wp-install.sh
RUN chmod a+x /tmp/wp-install.sh

ENTRYPOINT ["sh", "/tmp/wp-install.sh"]
