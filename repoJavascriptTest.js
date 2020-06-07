function addThemAll() {
    var count = 0;
    for (var i = 0; i < arguments.length; ++i) {
        count += arguments[i];
    }
    return count;
}

var a = addThemAll(1, 2, 3, 4);

console.log(a);