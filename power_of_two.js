/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    // Check if the number is greater than 0 and has only one bit set
    return n > 0 && (n & (n - 1)) === 0;
};
