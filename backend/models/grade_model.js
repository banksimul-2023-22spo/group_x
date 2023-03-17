const db = require('../database');

const grade = {
  getAll: function(callback) {
    return db.query('select idgrade,DATE_FORMAT(date_grade,"%d.%m.%Y") as date_grade,idstudent,idcourse,grade from grade', callback);
  },
  getById: function(id, callback) {
    return db.query('select idgrade,DATE_FORMAT(date_grade,"%d.%m.%Y") as date_grade,idstudent,idcourse,grade from grade where idgrade=?', [id], callback);
  },
  getByUsername:function(user,callback){
    return db.query('select name,grade,ects,DATE_FORMAT(date_grade,"%d.%m.%Y") as date_grade from course inner join grade on course.idcourse=grade.idcourse inner join student on student.idstudent=grade.idstudent where username=?',[user],callback);
  },
  add: function(grade, callback) {
    return db.query(
      'insert into grade (date_grade,idstudent,idcourse,grade) values(?,?,?,?)',
      [grade.date_grade, grade.idstudent, grade.idcourse, grade.grade],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from grade where idgrade=?', [id], callback);
  },
  update: function(id, grade, callback) {
    return db.query(
      'update grade set date_grade=?,idstudent=?, idcourse=?,grade? where idgrade=?',
      [grade.date_grade, grade.idstudent, grade.idcourse, grade.grade, id],
      callback
    );
  }
};
module.exports = grade;