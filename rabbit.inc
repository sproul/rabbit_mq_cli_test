RABBIT_CLI_DIR=/var/lib/rabbitmq/mnesia/*-plugins-expand/rabbitmq_management-*/priv/www/cli

if [ -z "$RABBIT_MQ_ADMIN_USER" ]; then
        echo "$0: error: expected a value for \"RABBIT_MQ_ADMIN_USER\" but saw nothing" 1>&2
        exit 1
fi
if [ -z "$RABBIT_MQ_ADMIN_PW" ]; then
        echo "$0: error: expected a value for \"RABBIT_MQ_ADMIN_PW\" but saw nothing" 1>&2
        exit 1
fi
if [ -z "$RABBIT_MQ_ADMIN_HOST" ]; then
        echo "$0: error: expected a value for \"RABBIT_MQ_ADMIN_HOST\" but saw nothing" 1>&2
        exit 1
fi
if [ ! -d $RABBIT_CLI_DIR ]; then
        echo "$0: error: could not find directory \"$RABBIT_CLI_DIR\"" 1>&2
        exit 1
fi

Admin()
{
        if !              python $RABBIT_CLI_DIR/rabbitmqadmin -H $RABBIT_MQ_ADMIN_HOST -u $RABBIT_MQ_ADMIN_USER -p $RABBIT_MQ_ADMIN_PW $@; then
                echo "$0: python $RABBIT_CLI_DIR/rabbitmqadmin -H $RABBIT_MQ_ADMIN_HOST -u $RABBIT_MQ_ADMIN_USER -p $RABBIT_MQ_ADMIN_PW $@ failed, exiting..." 1>&2
                exit 1
        fi
}
