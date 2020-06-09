var express = require('express');
var router = express.Router();

router.use(function timeLog(req, res, next) {
  console.log('Time: ', Date.now());
  next();
})

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('Users home page');
});

router.post('/', function (req, res, next) {
  res.send('Your request body: ' + req.body);
})

router.get('/about', function (req, res) {
  res.send('Users About Page');
})

module.exports = router;
