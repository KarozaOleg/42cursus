CREATE DATABASE wordpress;
CREATE USER 'mgaston'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON wordpress.* TO 'mgaston'@'localhost';
FLUSH PRIVILEGES;