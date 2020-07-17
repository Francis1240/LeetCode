import java.util.*;


class Solution {
    public List<List<Integer>> threeSum(int[] nums) { //N^2
        int n =  nums.length;
        HashMap<Integer, HashSet<Integer>> Mem = new HashMap<>();
        HashMap<Integer, Integer> count = new HashMap<>();
        for(int i  = 0; i < n; i++){
            if(count.containsKey(nums[i])){
                count.replace(nums[i], (count.get(nums[i]))+1);
            }else{
                count.put(nums[i], 1);
            }
        }

        List<List<Integer>> result = new ArrayList<>();

        for(int a: count.keySet()){
            for(int b: count.keySet()){
                if(count.get(a) > 1 && a == b){
                    //aaa
                    //aac

                    int c = -2*a;
                    if(a == c && count.get(a)>2){
                        if(!Mem.containsKey(a)){
                            HashSet<Integer> t2 = new HashSet<>();
                            t2.add(a);
                            Mem.put(a, t2);
                        } else if(!Mem.get(a).contains(a)){
                            Mem.get(a).add(a);
                        }
                    }else if(a != c && count.containsKey(c) && count.get(c)>0){
                        int x1 = a, x2 = c;
                        if(x2<x1){//caa
                            if(!Mem.containsKey(c)){
                                HashSet<Integer> t2 = new HashSet<>();
                                t2.add(a);
                                Mem.put(c, t2);
                            } else if(!Mem.get(c).contains(a)){
                                Mem.get(c).add(a);
                            }
                        }else{//aac
                            if(!Mem.containsKey(a)){
                                HashSet<Integer> t2 = new HashSet<>();
                                t2.add(a);
                                Mem.put(a, t2);
                            } else if(!Mem.get(a).contains(a)){
                                Mem.get(a).add(a);
                            }
                        }
                    }
                }else if(a != b){//abb, aba ignore
                    if(b == -a-b || a == -a-b || !count.containsKey(-a-b)){
                        continue;
                    }

                    //abc
                    int x1 = a, x2 = b, x3 = -a-b;
                    if(x3<x2){
                        int t = x3; x3 = x2; x2 = t;
                    }
                    if(x2<x1){
                        int t = x2; x2 = x1; x1 = t;
                    }
                    if(x3 < x2){
                        int t = x2; x2 = x3; x3 = t;
                    }
                    if(!Mem.containsKey(x1)){
                        HashSet<Integer> t2 = new HashSet<>();
                        t2.add(x2);
                        Mem.put(x1, t2);
                    } else if(!Mem.get(x1).contains(x2)){
                        Mem.get(x1).add(x2);
                    }
                }
            }
        }

        for (int a : Mem.keySet()) {
            for(int b: Mem.get(a)){
                int c = -(a+b);
                List<Integer> l = new ArrayList<>();
                l.add(a);
                l.add(b);
                l.add(c);
                result.add(l);
            }
        }
        return result;
    }

    
    public List<List<Integer>> threeSum_old(int[] nums) {//N^3
        int n =  nums.length;
        HashMap<Integer, HashMap<Integer, Integer>> Mem = new HashMap<>();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        int a = nums[i], b = nums[j], c = nums[k];
                        if(c<b){
                            int temp = b;
                            b = c;
                            c = temp;   
                        }
                        if(b<a){
                            int temp = a;
                            a = b;
                            b = temp;
                        }
                        if(c<b){
                            int temp = b;
                            b = c;
                            c = temp;
                        }
                        
                        if(!Mem.containsKey(a)){
                            HashMap<Integer, Integer> t = new HashMap<>();
                            t.put(b, c);
                            Mem.put(a, t);
                        } else if(!Mem.get(a).containsKey(b)){
                            Mem.get(a).put(b,c);
                        }

                    }
                }
            }
        }
        List<List<Integer>> result = new ArrayList<>();

        for (int a : Mem.keySet()) {
            for(int b: Mem.get(a).keySet()){
                int c = Mem.get(a).get(b);
                List<Integer> l = new ArrayList<>();
                l.add(a);
                l.add(b);
                l.add(c);
                result.add(l);
            }
        }

        return result;
    }
}