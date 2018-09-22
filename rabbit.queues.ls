#!/bin/bash
. `dirname $0`/rabbit.inc
Admin -f long -d 3 list queues
exit
$dp/rabbit_mq/scripts/rabbit.queues.ls