FROM php:7.2-apache
WORKDIR /var/www/html
RUN docker-php-ext-install pdo_mysql mysqli
RUN a2enmod rewrite

RUN apt-get update \
  && apt-get install \
    --no-install-recommends \
    --assume-yes \
  && apt-get install -y imagemagick \
  && apt-get install -y vim
