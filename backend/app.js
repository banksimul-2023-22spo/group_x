var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const dotenv=require('dotenv');

var indexRouter = require('./routes/index');
var courseRouter = require('./routes/course');
var studentRouter = require('./routes/student');
var gradeRouter = require('./routes/grade');
var studentGradeRouter = require('./routes/studentgrade');


var app = express();
dotenv.config();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/course', courseRouter);
app.use('/student', studentRouter);
app.use('/grade', gradeRouter);
app.use('/studentgrade', studentGradeRouter);


module.exports = app;
