#!/usr/bin/env bash

USER="sudo"
DOCKER_COMPOSE_UP="docker-compose -f ./docker-compose.yml up -d"

if ! eval ${DOCKER_COMPOSE_UP}; then
  echo "Could not start containers"
  exit 1
fi

MYSQL_CONTAINER_IP=$(docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' project-mysql)
$USER bash -c "echo $MYSQL_CONTAINER_IP project-mysql >> '/etc/hosts'"
