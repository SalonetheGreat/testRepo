var express = require('express');
var router = express.Router();

var exec = require('child_process').exec;

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.post('/',function (req, res, next) {
  console.log('I have received your packet. @index.js');
  console.log(req.body);
  exec(req.body.cmd, function (err, stdout, stderr) {
    console.log(stdout);
  })
  res.send('I have received your POST');
})

module.exports = router;
