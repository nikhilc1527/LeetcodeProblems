<?php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $a = [];
        for ($i = 0; $i < sizeof($nums); $i++) {
            if (array_key_exists($target - $nums[$i], $a)) {
                return [$i, $a[$target - $nums[$i]]];
            }
            else {
                $a[$nums[$i]] = $i;
            }
        }
        
    }
}

$s = new Solution();
$input = [5, 1, 6];
$res = $s->twoSum($input, 6);
print $res[0] . " ". $res[1] . "\n";
?>
