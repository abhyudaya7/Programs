// Calculate the number of ways of traversing an m*n grid 
// where you can move only down and right 

const gridTraveller = (m,n,memo = {}) => {
    const key = m + ',' + n;
    if (key in memo) 
        return memo[key];
    if (m === 1 && n === 1) 
        return 1;
    if (m === 0 || n === 0) 
        return 0;
    memo[key] = gridTraveller(m - 1,n,memo) + gridTraveller(m, n - 1,memo);
    return memo[key];
};

console.log(gridTraveller(30,30));