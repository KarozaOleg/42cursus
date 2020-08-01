# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    autoindex.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 15:28:46 by mgaston           #+#    #+#              #
#    Updated: 2020/07/30 15:28:47 by mgaston          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if grep -q "autoindex on" /etc/nginx/sites-available/localhost
then
	sed -i 's/autoindex on/autoindex off/' /etc/nginx/sites-available/localhost
	echo "autoindex disabled"
	service nginx restart
elif grep -q "autoindex off" /etc/nginx/sites-available/localhost
then
	sed -i 's/autoindex off/autoindex on/' /etc/nginx/sites-available/localhost
	echo "autoindex enablead"
	service nginx restart
fi
