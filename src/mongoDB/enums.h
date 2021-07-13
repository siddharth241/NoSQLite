namespace NoSQLite
{
  enum class MongoOpType
  {
    INSERT_ONE = 0,
    DELETE_ONE,
    FIND_ONE
  };

  enum class MongoError
  {
    SUCCESS = 0,
    COMMAND_NOT_SUPPORTED
  };
}
