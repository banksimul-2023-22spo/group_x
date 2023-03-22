const mysql = require('mysql2');
const connection = mysql.createPool({
  host: '127.0.0.1',
  user: 'netuser',
  password: '123netpass?X',
  database: 'peppidb',
  port:'3306'
});
module.exports = connection;