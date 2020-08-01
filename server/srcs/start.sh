# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 14:10:43 by mgaston           #+#    #+#              #
#    Updated: 2020/07/30 15:34:41 by mgaston          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

service mysql start
mysql < init.sql
service php7.3-fpm start
service nginx start

while true
do
	sleep 1
done