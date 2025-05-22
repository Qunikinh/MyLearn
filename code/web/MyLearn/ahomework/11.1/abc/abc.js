let strl = ' hELLO  wORLD this is a TEST ';
strl = strl.trim();
strl = strl.toLowerCase();
let str2 = strl.split(' ')
console.log(strl);
let str3 = []
for (const item of str2) {
    if (i != ' ') {
        str3.push(item.charAt(0).toUpperCase() + item.slice(1));
    }
}
console.log(str3);