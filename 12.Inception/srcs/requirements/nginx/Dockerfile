FROM alpine:3.13

RUN apk update
RUN apk upgrade
RUN apk add nginx
RUN apk add openssl
# openrc for rc-service
RUN apk add openrc

# Creer le dossier run/nginx (il n'est pas créé par defaut dans Alpine lors de l'installation de nginx)
RUN mkdir -p /run/nginx

# TLS installation
RUN mkdir /etc/nginx/certs
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/certs/localhost.pem -keyout /etc/nginx/certs/localhost.key -subj "/C=FR/ST=Nice/L=Nice/O=42 School/OU=epfennig/CN=localhost"
RUN ["chown", "0600", "/etc/nginx/certs"]

RUN rm -f /etc/nginx/http.d/default.conf
COPY ./conf/default.conf  /etc/nginx/http.d/default.conf

# Pour faire tourner le container, utilisation d'un daemon (nginx)
CMD ["nginx", "-g", "daemon off;"]

EXPOSE 443