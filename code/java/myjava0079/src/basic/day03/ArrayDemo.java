package basic.day03;

public class ArrayDemo {
    public static void main(String[] args) {
        int[] ary;
        System.out.println(ary[0]);
        System.out.println(ary);

        ary=null;
        //System.out.println(ary[0]);
        System.out.println(ary);
        
        System.out.println("======================================");
        int[] ary1= {1, 2, 3};
        System.out.println(Arrays.toString(ary1));
        ary1=null;
        System.out.println(ary1);
        System.out.println(Arrays.toString(ary1));

        //ary1={4, 5, 6};
        ary2=new int[] {4, 5, 6};
        ary1=ary2;
        System.out.println(Arrys.toString(ary1));

        //int[3] ary3={6,7,8};
        System.out.println("======================================");
        ary=new int[3];
        System.out.println(Arrays.toString(ary));
        System.out.println(ary[0]);
        char[] chs=new char[3];
        //System.out.println(Arrays.toString(chs));
        System.out.println((int)chs[1]);
        boolean[] b=new boolean[5];
        System.out.println(used[2]);
        String[] bookNames=new String[5];
        System.out.println(bookNames[2]);

        ary=new int[5];
        System.out.println(Arrays.toString(ary));
        ary=new int[]{2,3,4};

        System.out.println("======================================");
        int[] ary5=new int[3];
        System.out.println(ary5[0]);
        System.out.println(ary5[1]);
        System.out.println(ary5[2]);
        //System.out.println(ary5[3]);

        ary5[1]=8;
        System.out.println(ary5[0]);
        System.out.println(ary5[1]);
        System.out.println(ary5[2]);


        System.out.println("======================================");
        int[] ary6=ary5;
        ary5=new int[]{7,8,9,10};
        System.out.println(ary5[0]);
        System.out.println(ary5[1]);
        System.out.println(ary5[2]);
        System.out.println(ary5[3]);
        System.out.println(ary6[0]);
        System.out.println(ary6[1]);
        System.out.println(ary6[2]);
        
        String[] authors=new String[3];
        authors[0]="김유신";
        authors[1]="이순신";
        System.out.println(Arrays.toString(authors));


    }
}
