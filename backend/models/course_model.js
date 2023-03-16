const db = require('../database');

const course = {
  getAll: function(callback) {
    return db.query('select * from course', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from course where idcourse=?', [id], callback);
  },
  add: function(course, callback) {
    return db.query(
      'insert into course (name,ects) values(?,?)',
      [course.name, course.ects],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from course where idcourse=?', [id], callback);
  },
  update: function(id, course, callback) {
    return db.query(
      'update course set name=?,ects=? where idcourse=?',
      [course.name, course.ects, id],
      callback
    );
  }
};
module.exports = course;