const db = require('../database');

const login={
    checkPassword:function(login_username, callback){
        return db.query('select password from student where username=?',login_username,callback);
    }
}

module.exports=login;