var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        if(functions.length === 0) {
            resolve([]);
            return;
        }
        
        const res = new Array(functions.length).fill(null);

        let resolvedCount = 0;

        functions.forEach((el, idx) => {
            el().then((subResult) => {
                res[idx] = subResult;
                resolvedCount++;
                if(resolvedCount === functions.length) {
                    resolve(res);
                }
            }).catch((err) => {
                reject(err);
            })
        });
    });
};
