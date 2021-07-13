namespace NoSQLite
{
  enum class RedisOpType
  {
    SET = 0,
    GET,
    DEL,
    HSET,
    HGET,
    HDEL,
    KEYS
  };

  enum class RedisError
  {
    SUCCESS = 0,
    COMMAND_NOT_SUPPORTED
  };
}
