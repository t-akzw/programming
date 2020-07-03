#!/bin/sh

export PGPASSWORD=changeme
psql -U postgres -d postgres -h localhost -p 25432\
  -c "select * from ${1}"