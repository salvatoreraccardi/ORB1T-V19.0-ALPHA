# ORB1T V19.0 Alpha with Redis

## How to install redis on Raspberry Pi

First, go to your user's home directory

```cd ~```

To download Redis, the following link doesn't take a version as a parameter. Therefore, just copy and paste the command.

```wget http://download.redis.io/redis-stable.tar.gz```

Unarchive the package you've just downloaded.

```tar xzf redis*```

Go inside the Redis folder

```cd redis*```

Now let's build Redis from sources on your Raspberry Pi with following commands.

```sudo make```
```make test```

Edit the Redis configuration file to setup caching.

```sudo nano /etc/redis/redis.conf```

Use nano's CTRL+W function to search for the following entries. some are already set. But, there are still few values to set. For example,

- **daemonize** yes to run Redis as a Deamon.
- **stop-writes-on-bgsave-error no**, Redis stops on failure and requires a manual restart. Using this setting Redis will not stop on failure.
- **maxmemory** 70M, RAM is limited on a RaspberryPi, so 70 Mb is enough for most of my needs. If you need more memory, adjust this setting later.

```bind 127.0.0.1
port 6379
daemonize yes
stop-writes-on-bgsave-error no
rdbcompression yes
maxmemory 50M
maxmemory-policy allkeys-lru
```