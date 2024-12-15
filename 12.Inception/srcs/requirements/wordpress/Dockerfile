FROM alpine:3.13

RUN apk --update add curl wget \
	php7 php7-fpm php7-opcache php7-mysqli \
	php7-session php7-iconv php7-json \
	php7-gd php7-curl php7-xml php7-common \
	php7-imap php7-cgi php7-pdo php7-pdo_mysql \
	php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-redis \
	php7-gettext php7-ldap php7-ctype php7-dom php7-phar \
	openrc
# openrc for rc-service

COPY ./conf/wordpress_install.sh ./
COPY ./conf/wp-config.php ./

RUN mkdir -p /var/www/html

# Set le user et le groupe pour wordpress
RUN addgroup -g 82 -S www-data
RUN adduser -u 82 -D -S -G www-data www-data

RUN chmod 777 -R /var/www/html

RUN chown -R www-data:www-data /var/www/html

RUN rm -f /etc/php7/php-fpm.d/www.conf
COPY ./conf/www.conf /etc/php7/php-fpm.d/www.conf

CMD ["sh", "wordpress_install.sh"]

EXPOSE 9000
