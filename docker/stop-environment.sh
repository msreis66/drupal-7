#!/usr/bin/env bash

USER="sudo"
DOCKER_COMPOSE_DOWN="docker-compose down -v"

eval ${DOCKER_COMPOSE_DOWN}

$USER bash -c "sed --in-place "/project-mysql/d" /etc/hosts"