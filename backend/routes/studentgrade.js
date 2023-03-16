const express = require('express');
const router = express.Router();
const grade = require('../models/grade_model');

router.get('/:id',function(request,response){
    grade.getByStudentId(request.params.id,function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    })
});


module.exports=router;