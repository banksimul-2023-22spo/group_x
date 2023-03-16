const mysql=require('mysql2');

const connection=mysql.createPool(process.env.SQL_SERVER);

module.exports.connection;