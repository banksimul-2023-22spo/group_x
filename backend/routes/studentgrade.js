const express = require('express');
const router = express.Router();
const grade = require('../models/grade_model');

router.get('/:user',function(request,response){
    grade.getByUsername(request.params.user,function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    })
});


module.exports=router;