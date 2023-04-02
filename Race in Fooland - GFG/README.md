# Race in Fooland
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Fooland city has a special multi-lane running track. Lanes are numbered from <strong>1 to Tracks</strong>. The lanes have <strong>N</strong> horizontal barriers lying on it (due to some digging and construction work). The i<sup>th </sup>barrier cover lanes from <strong>Li1 to Li2</strong> (both inclusive). Also, the barriers may overlap. The athletes can’t run on the lanes on which barriers are present because they aren’t allowed to switch lanes anytime in the race. (Once a particular lane is allotted to an athlete he/she can’t switch his/her lane anytime during the race and there can be only one athlete on each lane.)</span></p>

<p><span style="font-size:18px">Now the race has to be organised tomorrow itself and the digging work could not be finished on time. The race would have to be organised on the same track only because Fooland city doesn’t have any other track. Help organizers in finding out how many athletes can run in a single race so that none of them would have to switch lanes.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 5, Track = 20
L<sub>i</sub> = {(1 3), (5 8), (8 13), 
           (14 15), (9 12)}

<strong>Output:</strong>
6

<strong>Explanation:</strong>
The barriers cover lanes from
 1 to 3, 5 to 8, 8 to 13, 
14 to 15 and 9 to 12. Hence, 
barriers are present on the 
lanes: {1, 2, 3, 5, 6, 7, 8,
 9, 10, 11, 12, 13, 14, 15}.

Hence, the lanes which doesn't
come under any barriers are 
{4, 16, 17, 18, 19, 20}.
So, there are 6 lanes on which
athletes can run – {4, 16, 17,
    18, 19, 20}
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>emptyLanes()</strong>&nbsp;which takes the pair array <strong>A[]</strong>, its size <strong>N </strong>and an integer <strong>Tracks </strong>as inputs and returns the number of athletes that can run in a single track.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(1)<br>
<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>6</sup><br>
1 ≤ Tracks ≤ 10<sup>6</sup><br>
1 ≤ Li1 ≤ Li2 ≤ Tracks<br>
The Barriers may overlap.</span></p>
</div>