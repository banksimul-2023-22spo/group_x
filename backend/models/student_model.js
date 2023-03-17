const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 10;

const student = {
    getAll: function (callback) {
        return db.query('select * from student', callback);
    },
    getById: function (user, callback) {
        return db.query('select * from student where username=?', [user], callback);
    },
    add: function (student, callback) {
        bcrypt.hash(student.password, saltRounds, function (err, hashed_password) {
            return db.query('insert into student (fname,lname,username,password) values(?,?,?,?)',
                [student.fname, student.lname, student.username, hashed_password],
                callback);
        });
    },
    delete: function (id, callback) {
        return db.query('delete from student where idstudent=?', [id], callback);
    },
    update: function (id, student, callback) {
        bcrypt.hash(student.password, saltRounds, function (err, hashed_password) {
            return db.query('update student set fname=?,lname=?,username=?,password=? where idstudent=?',
                [student.fname, student.lname, student.username, hashed_password,id],
                callback);
        });
    },
};
module.exports = student;