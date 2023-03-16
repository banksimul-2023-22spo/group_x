var express = require('express');
var router = express.Router();

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('Heippa '+process.env.SQL_SERVER);
});

module.exports = router;
