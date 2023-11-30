#!/bin/sh

while ! mysqladmin ping -h"$MYSQL_HOST" -u"$DB_USR" -p"$DB_PWD" --silent; do
	sleep 3
done

if [ ! -f wp-config.php ]; then
	wp core download --allow-root
	wp config create --dbname=$DB_NAME --dbuser=$DB_USR --dbpass=$DB_PWD --dbhost=$MYSQL_HOST --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
	wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
	wp user create $WP_USR $WP_EMAIL --role=editor --user_pass=$WP_PWD --allow-root
fi

if [ -f wp-config.php ]; then
	php-fpm81 -F
fi
