sleep 5

# Installation de Wordpress CLI pour la configuration depuis le server en SSH
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# le rendre executable puis le mettre dans le PATH des executables
chmod +x wp-cli.phar
mv -f wp-cli.phar /usr/local/bin/wp


# Telechargement de WordPress via le CLI (les files de base de Wordpress) en precisant le path
wp core download --allow-root --path="/var/www/html"

# Remplacer la config de base par ma config
rm -f /var/www/html/wp-config.php
mv /wp-config.php /var/www/html


# On lance l'installation de WordPress (Celle que l'on a normalement en se connectant sur localhost) avec les informations de l'admin
wp core install --allow-root --url=$DOMAIN_NAME --title=$TITLE --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --path="/var/www/html"

exec php-fpm7 -F
