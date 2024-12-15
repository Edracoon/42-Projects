# Installer mysql
# Initialiser les data - directory et crée les tables système dans la base de données mysql
/usr/bin/mysql_install_db --user=root --basedir=/usr --datadir=/var/lib/mysql

# Demonize Mariadb en precisant l'user et le dossier de stockage
# On lance mysql une premiere fois pour set mysql et creer les data-base
/usr/bin/mysqld --user=root --datadir=/var/lib/mysql & sleep 2
# Puis on devra le relancer pour que les ajouts soit pris en compte

# Creation de la data-base et du user associé
mysql -e "CREATE DATABASE IF NOT EXISTS \`${MARIADB_DATABASE}\`;"
mysql -e "CREATE USER IF NOT EXISTS \`${MARIADB_USER}\`@'localhost' IDENTIFIED BY '${MARIADB_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON \`${MARIADB_DATABASE}\`.* TO \`${MARIADB_USER}\`@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"

# ALTER USER = Permet de modifier un user, j'ajoute un mdp au root pour bloquer la connection root sans mdp
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';"
# Actualiser les droits mais pas la db
mysql -e "FLUSH PRIVILEGES;"

# On kill et relance mysql pour que les changements et les creations soit pris en compte
pkill mysqld

/usr/bin/mysqld --user=root --datadir=/var/lib/mysql
