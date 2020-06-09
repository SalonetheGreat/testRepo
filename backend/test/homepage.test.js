var supertest = require('supertest');
var app = require('../app');
var assert = require('chai').assert;

describe('homepage', function () {
    it('Testcase for GET \'/\'', function (done) {
        supertest(app).get('/')
            .expect(200, done);
    })

    it('Testcase for POST \'/\'', function (done) {
        supertest(app).post('https://xtrap100.d2.comp.nus.edu.sg:4002/')
            .send({
                name: 'Sha Long',
                Birthday: '0310',
                cmd: 'ls'
            })
            .expect(200, done);
    });
});

describe('userspage', () => {
    it('should post sth to /users', function (done) {
        supertest(app).post('/users')
            .send({
                name: 'JSON file posted for users',
                date: {
                    year: 2020,
                    month: 6,
                    date: 8
                }
            })
            .expect(200, done);
    })
});