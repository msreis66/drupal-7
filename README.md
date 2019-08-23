# drupal-7

## Starting Environment
Go to ./docker and run the script `start-environment.sh`
Then run the command `docker exec -i project-mysql mysql -u root -proot -h project-mysql drupal7 < ../docroot/sites/default/drupal7.sql`
All set, now just access `localhost`

The admin credentials for Drupal are: user=admin, password=admin
And for mysql are -u root -p root