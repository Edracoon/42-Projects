<?php
define( 'DB_NAME', getenv('MARIADB_DATABASE'));

/** Utilisateur de la base de données MySQL. */
define('DB_USER', getenv('MARIADB_USER'));

/** Mot de passe de la base de données MySQL. */
define('DB_PASSWORD', getenv('MARIADB_PASSWORD'));

define('DB_HOST', getenv('WORDPRESS_DB_HOST'));

define('DB_CHARSET', 'utf8');

#define('WP_SITEURL', getenv('DOMAIN_NAME') );
#define('WP_HOME', 'localhost' );

define('DB_COLLATE', '' );

# test fix
#define('WP_ALLOW_REPAIR', true);

define('AUTH_KEY',         'zrgec5g:uXDG0q(<aru=<=BRlb6*yu}bw&&B$Npk$^Yl4S_593yxglF<WYSd?yP9');
define('SECURE_AUTH_KEY',  ':?a/k$^Ju.;/Fg;>iJQaKF>|n1[P!&!-i8Xc|=&,(&00ph1l+<A}S% tLN2Z,[NO');
define('LOGGED_IN_KEY',    'nPu}r0=1)T$H--W?+0W<?>^6ys+LwP~=Zlb{Y*`:dp3kmYf>?mV@x|cxE0)gUC3G');
define('NONCE_KEY',        '#O}OrAJpw7(UhMSECh+n6Ld~._0YGeE:pcnO@O;yLx--{YFs+IDLQC06?i`VH,9M');
define('AUTH_SALT',        'wkrhZ)DX7zWeC[qey})qc6J%DMa6@j-p%6Mo?;R4*5SDi5,1nsug/6pCOW]?Iqrm');
define('SECURE_AUTH_SALT', 'y6yf__gH-=.+*$VK2Pe_auVEc.7jJ)L5sJq`vQ]{-x+ATiNQet(+#Y)Dv^;G1^<l');
define('LOGGED_IN_SALT',   'i; My*8G&4P0C:S/=u0B^&G[0j*rpq5w@V(S=Y>${D6_*``(-shm~aNls|qd%8$P');
define('NONCE_SALT',       'pr:AOva;MB!h`|}#|H.6j*ik:StMw+Mmgz($}%Q^:tRdQq hs|$j@-jXZ8R(-{l&');
define('CONCATENATE_SCRIPTS', false);
define( 'WP_CACHE_KEY_SALT', 'localhost' );

$table_prefix = 'wp_';

define('WP_DEBUG', false);
if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';