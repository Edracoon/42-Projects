# Inception

-- nginx -- \
un serveur web, stoque les fichiers qui compose le site web, sers a faire
la liaison entre les differents services notamment via FastCGI pour Wordpress et php-fpm
C'est en quelques sortes la plateforme 

-- wordpress && php-fpm -- \
wordpress : gestion site web et base de données mariadb

php-fpm   : Fast Process Manager, il va servir de daemon sur le PID 1 et va faire tourner le container en attendant des requetes
            CGI ( celles de nginx ).
            Permet aussi l'interpretation des fichiers .php

-- mariadb -- \
gestionnaire de base de données 
