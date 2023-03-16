const mysql=require('mysql2');
const dotenv=require('dotenv');

dotenv.config();

const connection=mysql.createPool(process.env.SQL_SERVER);

module.exports=connection;