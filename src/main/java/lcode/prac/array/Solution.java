package lcode.prac.array;

import java.util.*;
import java.util.stream.Collectors;

// https://leetcode.com/problems/combination-sum-iii/
public class Solution {
//    public boolean squareIsWhite(String coordinates) {
//        int b = coordinates.charAt(0) - 'a';
//        int a= Integer.parseInt(coordinates.substring(1));
//        return ((a + b) % 2) == 0;
//    }
//
//    public boolean areSentencesSimilar(String sentence1, String sentence2) {
//        String[] split1 = sentence1.split(" ");
//        String[] split2 = sentence2.split(" ");
//        if (split1.length == split2.length) {
//            for (int i = 0; i < split1.length; i++) {
//                if (!split1[i].equals(split2[i]))
//                    return false;
//            }
//            return true;
//        } else if (split1.length > split2.length) {
//            String[] tmp = split1;
//            split1 = split2;
//            split2 = tmp;
//        }
//
//
//
//        int startIdx = 0;
//        for (; startIdx < split1.length; startIdx++) {
//            if (!split1[startIdx].equals(split2[startIdx])) {
//                break;
//            }
//        }
//
//        int endIdx = 0;
//        for (; endIdx < split1.length; endIdx++) {
//            int idx1 = split1.length - 1 - endIdx;
//            int idx2 = split2.length - 1 - endIdx;
//            if (!split1[idx1].equals(split2[idx2])) {
//                break;
//            }
//        }
//
//        return (startIdx + endIdx >= split1.length);
//    }
//
//    public int maxHappyGroups(int batchSize, int[] groups) {
//        // 1. group == batch
//        // 2. group + group = batch times
//        // 3. group + group + group =
//        Map<Integer, Integer> modCount = new HashMap<>();
//        int max = 0;
//
//        for (int i = 0; i < batchSize; i++) {
//            modCount.put(i, 0);
//        }
//
//        for (int group : groups) {
//            int mod = group % batchSize;
//            Integer aDefault = modCount.getOrDefault(mod, 0);
//            aDefault++;
//            modCount.put(mod, aDefault);
//        }
//
//        // for 0
//        max += modCount.get(0);
//        modCount.put(0, 0);
//        // pair them
//        for (int i = 1; i <= (batchSize / 2); i++) {
//            int pair = batchSize - i;
//            if (pair > i) {
//                int nbPair = Math.min(modCount.get(i), modCount.get(pair));
//                modCount.put(i, modCount.get(i) - nbPair);
//                modCount.put(pair, modCount.get(pair) - nbPair);
//                max += nbPair;
//            } else if (pair == i) {
//                int nbPair = modCount.get(i) / 2;
//                modCount.put(i, modCount.get(i) - 2 * nbPair);
//                max += nbPair;
//            }
//        }
//
//        // remining:
//        int[] remining = new int[batchSize];
//        for (Map.Entry<Integer, Integer> entry : modCount.entrySet()) {
//            int mod = entry.getKey();
//            int count = entry.getValue();
//            remining[mod] = count;
//        }
//
//        // backtracking
//        max += bt(remining, batchSize, batchSize, new HashMap<>());
//        return max;
//    }
//
//    public int bt(int[] groups, int rest, int batchSize, Map<String,Integer> cache) {
//        int currentMax = -1;
//        StringBuilder state = new StringBuilder();
//        int nums = 0;
//        for (int group : groups) {
//            state.append(group);
//            nums += group;
//        }
//        if (nums == 0) {
//            return (rest != batchSize) ? 1 : 0;
//        }
//        state.append(rest);
//        String stateStr = state.toString();
//        if (cache.containsKey(stateStr)) {
//            return cache.get(stateStr);
//        }
//        int base = 0;
//        if (rest == 0) {
//            base = 1;
//            rest = batchSize;
//        } else if (rest < 0) {
//            rest += batchSize;
//        }
//        int incr = 0;
//        for (int i = batchSize - 1; i > 0; i--) {
//            if (groups[i] == 0) {
//                continue;
//            }
//            groups[i] -= 1;
//            int tmp = bt(groups, rest - i, batchSize, cache);
//            groups[i] += 1;
//
//            incr = Math.max(incr, tmp);
//        }
//        cache.put(stateStr, base + incr);
//        return cache.get(stateStr);
//    }
//
//    public int countNicePairs(int[] nums) {
//        Map<Integer, List<String>> numsPerDigit = new HashMap<>();
//        long palimCount = 0;
//        for (int num : nums) {
//            String s = Integer.toString(num);
//            if (isPalim(s)) {
//                palimCount ++;
//            } else {
//                List<String> l = numsPerDigit.getOrDefault(s.length(), new ArrayList<>());
//                l.add(s);
//                numsPerDigit.put(s.length(), l);
//            }
//        }
//
//        long res = palimCount * (palimCount - 1) / 2;
//
//        for (Map.Entry<Integer, List<String>> en : numsPerDigit.entrySet()) {
//            int nbDigits = en.getKey();
//            List<String> l = en.getValue();
//
//            for (int i = 0; i < l.size(); i++) {
//                for (int j = i + 1; j < l.size(); j++) {
//                    String first = l.get(i);
//                    String second = l.get(j);
//                    boolean allGood = true;
//                    for (int i1 = 0; i1 < (first.length() / 2); i1++) {
//                        int endIdx = nbDigits - 1 - i1;
//                        if ((first.charAt(i1) - '0') + (second.charAt(i1) - '0') !=
//                                (first.charAt(endIdx) - '0') + (second.charAt(endIdx) - '0')) {
//                            allGood = false;
//                            break;
//                        }
//                    }
//                    if (allGood) {
//                        res ++;
//                    }
//                }
//            }
//        }
//        return (int)(res % ((int) (Math.pow(10, 9) + 7)));
//    }
//
//    public boolean isPalim(String num) {
//        for (int i = 0; i < num.length(); i++) {
//            if (num.charAt(i) != num.charAt(num.length() - 1 - i)){
//                return false;
//            }
//        }
//        return true;
//    }
//
//    public int[] solve(int[] nums) {
//
//        List<Integer> res = new ArrayList<>();
//
//        for (int i = 0; i < nums.length; i++) {
//            if (i == 0) {
//                if (nums[i] > nums[i + 1]) {
//                    res.add(i);
//                }
//            }
//            else if (i == nums.length - 1) {
//                if (nums[i] > nums[i - 1]) {
//                    res.add(i);
//                }
//            } else {
//                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
//                    res.add(i);
//                }
//            }
//        }
//        return res.stream().mapToInt(i -> i).toArray();
//    }
//
//    public boolean solve1(String s, String[][] pairs) {
//        int[] caracMap = new int[26];
//        for (int i = 0; i < caracMap.length; i++) {
//            caracMap[i] = i;
//        }
//
//        int max = 1;
//
//        for (String[] pair : pairs) {
//            char a = pair[0].charAt(0);
//            char b = pair[1].charAt(0);
//            if (caracMap[a- 'a'] == 0 && caracMap[b- 'a'] == 0) {
//                caracMap[a- 'a'] = max;
//                caracMap[b- 'a'] = max++;
//            } else {
//                if (caracMap[a- 'a'] == 0) {
//                    caracMap[a- 'a'] =  caracMap[b- 'a'];
//                } else if (caracMap[b- 'a'] == 0) {
//                    caracMap[b- 'a'] =  caracMap[a- 'a'];
//                } else {
//                    int newV = caracMap[a-'a'];
//                    int oldV = caracMap[b-'a'];
//
//                    for (int k = 0; k < caracMap.length; k++) {
//                        if (caracMap[k] == oldV) {
//                            caracMap[k] = newV;
//                        }
//                    }
//                }
//            }
//
//        }
//        return isPalin(s, caracMap);
//
//    }
//
//    public boolean isPalin ( String s, int[] caracMap) {
//        for (int i = 0; i < s.length(); i++) {
//            int j = s.length() - 1 - i;
//            if (i <= j) {
//                char a = s.charAt(i);
//                char b = s.charAt(j);
//                if (caracMap[a- 'a'] != caracMap[b- 'a']) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//
//    public int[][] solve3(int[][] intervals) {
//        // index 0 -> -2 ^ 31 + 1
//
//        List<int[]> intervalList = new ArrayList<>();
//        int startK = Integer.MAX_VALUE;
//        int endK = Integer.MIN_VALUE;
//        for (int i = 0; i < intervals.length; i++) {
//            intervalList.add(intervals[i]);
//            endK = Math.max(intervals[i][1], endK);
//        }
//        intervalList.sort((a, b) -> Integer.compare(a[0], b[0]));
//        startK = intervalList.get(0)[0];
//        List<int[]> res = new ArrayList<>();
//        int max = 0;
//        int[] curr = new int[] {0, 0};
//        int currInterval = 0;
//        int currWei = 0;
//        for (int k = startK; k <= endK; k++) {
//            currWei = 0;
//            for (int i = currInterval; i < intervalList.size(); i++) {
//                int[] interv = intervalList.get(i);
//                int start = interv[0];
//                int end = interv[1];
//                int weight = interv[2];
//                if (start > k) {
//                    break;
//                } else if (end < k ) {
//                    currInterval++;
//                } else if (start <= k && end >= k){
//                    currWei += weight;
//                }
//            }
//            if (currWei > max) {
//                max = currWei;
//                res.clear();
//                curr = new int[] {k, k};
//            } else if (currWei == max){
//                if (k - curr[1] == 1) {
//                    curr[1] += 1;
//                } else {
//                    res.add(curr);
//                    curr = new int[] {k, k};
//                }
//            }
//        }
//
//        if (currWei == max) {
//            res.add(curr);
//        }
//
//        int[][] result = new int[res.size()][];
//        for (int i = 0; i < res.size(); i++) {
//            result[i] = res.get(i);
//        }
//
//        return result;
//
//    }
//
//    public int purchasePlans(int[] nums, int target) {
//        int[] sorted = Arrays.stream(nums).sorted().toArray();
//        int first = 0;
//        int second = nums.length - 1;
//        long result = 0;
//        int divider = (int)(Math.pow(10, 9) + 7);
//        for (int i = 0; i < sorted.length; i++) {
//            first = i;
//            while (nums[first] + nums[second] > target && first < second) {
//                second--;
//            }
//            if (first >= second) {
//                result += (long)(first + 1) * (long) (nums.length - (second + 1));
//                second++;
//            } else {
//                result += (long)(first + 1) * (long) (nums.length - second);
//            }
//        }
//        return (int) (result % divider);
//    }
//
//    public int orchestraLayout(int num, int xPos, int yPos) {
//        int nbLevel = Math.min(Math.min(xPos, yPos), Math.min(num - 1 - xPos, num - 1 - yPos));
//        long alreadyMoved = 0;
//        for (int i = 0; i < nbLevel; i++) {
//            long current = num - i * 2;
//            alreadyMoved += (current * 4 - 4);
//        }
//        // 4 cases
//        long nbElement = 0;
//        long currentSize = num - (nbLevel) * 2;
//        if (nbLevel == xPos) {
//            int startingX = nbLevel;
//            int startingY = nbLevel;
//            nbElement = yPos - startingY + 1;
//        } else if (nbLevel == num - 1 - yPos) {
//            int startingX = nbLevel;
//            int startingY = yPos;
//            nbElement = currentSize + xPos - startingX;
//        } else if (nbLevel == num - 1 - xPos) {
//            int startingX = num - 1 - nbLevel;
//            int startingY = num - 1 - nbLevel;
//            nbElement = currentSize * 2 - 1 + (startingY - yPos);
//        } else if (nbLevel == yPos) {
//            int startingX = num - 1 - nbLevel;
//            int startingY = nbLevel;
//            nbElement = currentSize * 3 - 2 + (startingX - xPos);
//        }
//        int v = (int)((alreadyMoved + nbElement) % 9);
//        return (v == 0) ? 9 : v ;
//    }
//
//    public boolean squareIsWhite(String coordinates) {
//        int b = coordinates.charAt(0) - 'a';
//        int a= Integer.parseInt(coordinates.substring(1));
//        return ((a + b) % 2) == 0;
//    }
//
//    public boolean areSentencesSimilar(String sentence1, String sentence2) {
//        String[] split1 = sentence1.split(" ");
//        String[] split2 = sentence2.split(" ");
//        if (split1.length == split2.length) {
//            for (int i = 0; i < split1.length; i++) {
//                if (!split1[i].equals(split2[i]))
//                    return false;
//            }
//            return true;
//        } else if (split1.length > split2.length) {
//            String[] tmp = split1;
//            split1 = split2;
//            split2 = tmp;
//        }
//
//
//
//        int startIdx = 0;
//        for (; startIdx < split1.length; startIdx++) {
//            if (!split1[startIdx].equals(split2[startIdx])) {
//                break;
//            }
//        }
//
//        int endIdx = 0;
//        for (; endIdx < split1.length; endIdx++) {
//            int idx1 = split1.length - 1 - endIdx;
//            int idx2 = split2.length - 1 - endIdx;
//            if (!split1[idx1].equals(split2[idx2])) {
//                break;
//            }
//        }
//
//        return (startIdx + endIdx >= split1.length);
//    }
//
//    public int maxHappyGroups(int batchSize, int[] groups) {
//        // 1. group == batch
//        // 2. group + group = batch times
//        // 3. group + group + group =
//        Map<Integer, Integer> modCount = new HashMap<>();
//        int max = 0;
//
//        for (int i = 0; i < batchSize; i++) {
//            modCount.put(i, 0);
//        }
//
//        for (int group : groups) {
//            int mod = group % batchSize;
//            Integer aDefault = modCount.getOrDefault(mod, 0);
//            aDefault++;
//            modCount.put(mod, aDefault);
//        }
//
//        // for 0
//        max += modCount.get(0);
//        modCount.put(0, 0);
//        // pair them
//        for (int i = 1; i <= (batchSize / 2); i++) {
//            int pair = batchSize - i;
//            if (pair > i) {
//                int nbPair = Math.min(modCount.get(i), modCount.get(pair));
//                modCount.put(i, modCount.get(i) - nbPair);
//                modCount.put(pair, modCount.get(pair) - nbPair);
//                max += nbPair;
//            } else if (pair == i) {
//                int nbPair = modCount.get(i) / 2;
//                modCount.put(i, modCount.get(i) - 2 * nbPair);
//                max += nbPair;
//            }
//        }
//
//        // remining:
//        int[] remining = new int[batchSize];
//        for (Map.Entry<Integer, Integer> entry : modCount.entrySet()) {
//            int mod = entry.getKey();
//            int count = entry.getValue();
//            remining[mod] = count;
//        }
//
//        // backtracking
//        max += bt(remining, batchSize, batchSize, new HashMap<>());
//        return max;
//    }
//
//    public int bt(int[] groups, int rest, int batchSize, Map<String,Integer> cache) {
//        int currentMax = -1;
//        StringBuilder state = new StringBuilder();
//        int nums = 0;
//        for (int group : groups) {
//            state.append(group);
//            nums += group;
//        }
//        if (nums == 0) {
//            return (rest != batchSize) ? 1 : 0;
//        }
//        state.append(rest);
//        String stateStr = state.toString();
//        if (cache.containsKey(stateStr)) {
//            return cache.get(stateStr);
//        }
//        int base = 0;
//        if (rest == 0) {
//            base = 1;
//            rest = batchSize;
//        } else if (rest < 0) {
//            rest += batchSize;
//        }
//        int incr = 0;
//        for (int i = batchSize - 1; i > 0; i--) {
//            if (groups[i] == 0) {
//                continue;
//            }
//            groups[i] -= 1;
//            int tmp = bt(groups, rest - i, batchSize, cache);
//            groups[i] += 1;
//
//            incr = Math.max(incr, tmp);
//        }
//        cache.put(stateStr, base + incr);
//        return cache.get(stateStr);
//    }
//
//    public int countNicePairs(int[] nums) {
//        Map<Integer, List<String>> numsPerDigit = new HashMap<>();
//        long palimCount = 0;
//        for (int num : nums) {
//            String s = Integer.toString(num);
//            if (isPalim(s)) {
//                palimCount ++;
//            } else {
//                List<String> l = numsPerDigit.getOrDefault(s.length(), new ArrayList<>());
//                l.add(s);
//                numsPerDigit.put(s.length(), l);
//            }
//        }
//
//        long res = palimCount * (palimCount - 1) / 2;
//
//        for (Map.Entry<Integer, List<String>> en : numsPerDigit.entrySet()) {
//            int nbDigits = en.getKey();
//            List<String> l = en.getValue();
//
//            for (int i = 0; i < l.size(); i++) {
//                for (int j = i + 1; j < l.size(); j++) {
//                    String first = l.get(i);
//                    String second = l.get(j);
//                    boolean allGood = true;
//                    for (int i1 = 0; i1 < (first.length() / 2); i1++) {
//                        int endIdx = nbDigits - 1 - i1;
//                        if ((first.charAt(i1) - '0') + (second.charAt(i1) - '0') !=
//                                (first.charAt(endIdx) - '0') + (second.charAt(endIdx) - '0')) {
//                            allGood = false;
//                            break;
//                        }
//                    }
//                    if (allGood) {
//                        res ++;
//                    }
//                }
//            }
//        }
//        return (int)(res % ((int) (Math.pow(10, 9) + 7)));
//    }
//
//    public boolean isPalim(String num) {
//        for (int i = 0; i < num.length(); i++) {
//            if (num.charAt(i) != num.charAt(num.length() - 1 - i)){
//                return false;
//            }
//        }
//        return true;
//    }
//
//    public int[] solve(int[] nums) {
//
//        List<Integer> res = new ArrayList<>();
//
//        for (int i = 0; i < nums.length; i++) {
//            if (i == 0) {
//                if (nums[i] > nums[i + 1]) {
//                    res.add(i);
//                }
//            }
//            else if (i == nums.length - 1) {
//                if (nums[i] > nums[i - 1]) {
//                    res.add(i);
//                }
//            } else {
//                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
//                    res.add(i);
//                }
//            }
//        }
//        return res.stream().mapToInt(i -> i).toArray();
//    }
//
//    public boolean solve1(String s, String[][] pairs) {
//        int[] caracMap = new int[26];
//        for (int i = 0; i < caracMap.length; i++) {
//            caracMap[i] = i;
//        }
//
//        int max = 1;
//
//        for (String[] pair : pairs) {
//            char a = pair[0].charAt(0);
//            char b = pair[1].charAt(0);
//            if (caracMap[a- 'a'] == 0 && caracMap[b- 'a'] == 0) {
//                caracMap[a- 'a'] = max;
//                caracMap[b- 'a'] = max++;
//            } else {
//                if (caracMap[a- 'a'] == 0) {
//                    caracMap[a- 'a'] =  caracMap[b- 'a'];
//                } else if (caracMap[b- 'a'] == 0) {
//                    caracMap[b- 'a'] =  caracMap[a- 'a'];
//                } else {
//                    int newV = caracMap[a-'a'];
//                    int oldV = caracMap[b-'a'];
//
//                    for (int k = 0; k < caracMap.length; k++) {
//                        if (caracMap[k] == oldV) {
//                            caracMap[k] = newV;
//                        }
//                    }
//                }
//            }
//
//        }
//        return isPalin(s, caracMap);
//
//    }
//
//    public boolean isPalin ( String s, int[] caracMap) {
//        for (int i = 0; i < s.length(); i++) {
//            int j = s.length() - 1 - i;
//            if (i <= j) {
//                char a = s.charAt(i);
//                char b = s.charAt(j);
//                if (caracMap[a- 'a'] != caracMap[b- 'a']) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//
//    public int[][] solve3(int[][] intervals) {
//        // index 0 -> -2 ^ 31 + 1
//
//        List<int[]> intervalList = new ArrayList<>();
//        int startK = Integer.MAX_VALUE;
//        int endK = Integer.MIN_VALUE;
//        for (int i = 0; i < intervals.length; i++) {
//            intervalList.add(intervals[i]);
//            endK = Math.max(intervals[i][1], endK);
//        }
//        intervalList.sort((a, b) -> Integer.compare(a[0], b[0]));
//        startK = intervalList.get(0)[0];
//        List<int[]> res = new ArrayList<>();
//        int max = 0;
//        int[] curr = new int[] {0, 0};
//        int currInterval = 0;
//        int currWei = 0;
//        for (int k = startK; k <= endK; k++) {
//            currWei = 0;
//            for (int i = currInterval; i < intervalList.size(); i++) {
//                int[] interv = intervalList.get(i);
//                int start = interv[0];
//                int end = interv[1];
//                int weight = interv[2];
//                if (start > k) {
//                    break;
//                } else if (end < k ) {
//                    currInterval++;
//                } else if (start <= k && end >= k){
//                    currWei += weight;
//                }
//            }
//            if (currWei > max) {
//                max = currWei;
//                res.clear();
//                curr = new int[] {k, k};
//            } else if (currWei == max){
//                if (k - curr[1] == 1) {
//                    curr[1] += 1;
//                } else {
//                    res.add(curr);
//                    curr = new int[] {k, k};
//                }
//            }
//        }
//
//        if (currWei == max) {
//            res.add(curr);
//        }
//
//        int[][] result = new int[res.size()][];
//        for (int i = 0; i < res.size(); i++) {
//            result[i] = res.get(i);
//        }
//
//        return result;
//
//    }
//
//    public int purchasePlans(int[] nums, int target) {
//        int[] sorted = Arrays.stream(nums).sorted().toArray();
//        int first = 0;
//        int second = nums.length - 1;
//        long result = 0;
//        int divider = (int)(Math.pow(10, 9) + 7);
//        for (int i = 0; i < sorted.length; i++) {
//            first = i;
//            while (nums[first] + nums[second] > target && first < second) {
//                second--;
//            }
//            if (first >= second) {
//                result += (long)(first + 1) * (long) (nums.length - (second + 1));
//                second++;
//            } else {
//                result += (long)(first + 1) * (long) (nums.length - second);
//            }
//        }
//        return (int) (result % divider);
//    }
//
//    public int orchestraLayout(int num, int xPos, int yPos) {
//        int nbLevel = Math.min(Math.min(xPos, yPos), Math.min(num - 1 - xPos, num - 1 - yPos));
//        long alreadyMoved = 0;
//        for (int i = 0; i < nbLevel; i++) {
//            long current = num - i * 2;
//            alreadyMoved += (current * 4 - 4);
//        }
//        // 4 cases
//        long nbElement = 0;
//        long currentSize = num - (nbLevel) * 2;
//        if (nbLevel == xPos) {
//            int startingX = nbLevel;
//            int startingY = nbLevel;
//            nbElement = yPos - startingY + 1;
//        } else if (nbLevel == num - 1 - yPos) {
//            int startingX = nbLevel;
//            int startingY = yPos;
//            nbElement = currentSize + xPos - startingX;
//        } else if (nbLevel == num - 1 - xPos) {
//            int startingX = num - 1 - nbLevel;
//            int startingY = num - 1 - nbLevel;
//            nbElement = currentSize * 2 - 1 + (startingY - yPos);
//        } else if (nbLevel == yPos) {
//            int startingX = num - 1 - nbLevel;
//            int startingY = nbLevel;
//            nbElement = currentSize * 3 - 2 + (startingX - xPos);
//        }
//        int v = (int)((alreadyMoved + nbElement) % 9);
//        return (v == 0) ? 9 : v ;
//    }
//
//
//
//    public int magicTower(int[] nums) {
//        int posSum = 0;
//        int negSum = 0;
//        int sum = 0;
//
//        for (int i = 0; i < nums.length; i++) {
//            sum += nums[i];
//        }
//
//        if (sum < 0) {
//            return -1;
//        }
//        return dp(nums, 0, 0, 0, 0, new HashMap<>());
//    }
//
//    public int dp(int[] nums, int current, int idx, int movedCount, int moved,  Map<String, Integer> mem) {
//
//        String status = Integer.toString(idx) + " " + Integer.toString(moved);
//
//        if (current < 0) {
//            mem.put(status, -1);
//            return -1;
//        }
//        if (idx >= nums.length) {
//            // end
//            int v = mem.getOrDefault(status, 0);
//            mem.put(status, Math.min(v, movedCount));
//            return mem.get(status);
//        }
//        if (mem.containsKey(status)) {
//            return mem.get(status);
//        }
//        while (nums[idx] > 0 ) {
//            current += nums[idx];
//            idx++;
//        }
//        // not move
//        current -= nums[idx];
//        int res1 = dp(nums, current, idx + 1, movedCount, moved, mem);
//        current += nums[idx];
//        // move
//        moved += nums[idx];
//        int res2 = dp(nums, current, idx + 1, movedCount + 1, moved, mem);
//        moved -= nums[idx];
//        status = Integer.toString(idx) + " " + Integer.toString(moved);
//        if (res1 == -1) {
//            mem.put(status, res2);
//            return res2;
//        } else if (res2 == -1) {
//            mem.put(status, res1);
//            return res1;
//        } else {
//            int res = Math.min(res1, res2);
//            mem.put(status, res);
//            return res1;
//        }
//    }

    public int magicTower(int[] nums) {
        long sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        if (sum < 0) {
            return -1;
        }
        sum = 0;
        PriorityQueue<Integer> q = new PriorityQueue<>(Comparator.naturalOrder());
        int index = 0;
        int res = 0;
//        int j = nums.length;

        while (index < nums.length) {
            if (nums[index] < 0) {
                q.offer(nums[index]);
            }
            sum += nums[index];

            while (sum < 0) {
                res ++;
//                j --;
                sum -= q.poll();
            }
            index++;
        }
        return res;
    }

    public int[][] solve(int[][] intervals) {
        List<int[]> eventList = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++) {
            int[] interval = intervals[i];
            eventList.add(new int[] {interval[0], interval[2]});
            eventList.add(new int[] {interval[1], -interval[2]});
        }
        eventList.sort((e1, e2) -> {
            if (e1[0] == e2[0]) {
                return e2[1] - e1[1];
            }
            return e1[0] - e2[0];
        });

        int max = 0;
        int current = 0;
        for (int i = 0; i < eventList.size(); i++) {
            current += eventList.get(i)[1];
            max = Math.max(current, max);
        }

        List<int[]> res = new ArrayList<>();
        int last = -1;
        current = 0;
        for (int i = 0; i < eventList.size(); i++) {
            int[] event = eventList.get(i);
            if (event[1] < 0) {
                if (current == max) {
                    res.add(new int[] {last, event[0]});
                }
                last = -1;
            } else {
                last = event[0];
            }
            current += event[1];
        }

        List<int[]> merged = new ArrayList<>();
        for (int i = 0; i < res.size();) {
            int start = res.get(i)[0];
            int end = res.get(i)[1];
            while (i+1 < res.size() && res.get(i + 1)[0] - end == 1) {
                i++;
                end = res.get(i)[1];
            }
            merged.add(new int[]{start, end});
            i++;
        }

        int[][] result = new int[merged.size()][];

        for (int i = 0; i < merged.size(); i++) {
            result[i] = merged.get(i);
        }

        return result;
    }

}
