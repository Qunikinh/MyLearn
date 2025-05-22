window.onload = function () {
    let AQI = prompt("请输入空气质量指数");
    if (AQI >= 0 && AQI <= 50) {
        alert("优\n空气清新，参加户外活动");
        console.log("优\n空气清新，参加户外活动");
    } else if (AQI >= 51 && AQI <= 100) {
        alert("良\n可以正常进行户外活动");
        console.log("良\n可以正常进行户外活动");
    } else if (AQI >= 101 && AQI <= 150) {
        alert("轻度污染\n敏感人群减少体力消耗大的户外活动");
        console.log("轻度污染\n敏感人群减少体力消耗大的户外活动");
    } else if (AQI >= 151 && AQI <= 200) {
        alert("中度污染\n对敏感人群影响较大，减少户外活动");
        console.log("中度污染\n对敏感人群影响较大，减少户外活动");
    } else if (AQI >= 201 && AQI <= 300) {
        alert("重度污染\n所有人适当减少户外活动");
        console.log("重度污染\n所有人适当减少户外活动");
    } else {
        alert("严重污染\n尽量不要留在户外");
        console.log("严重污染\n尽量不要留在户外");
    }
}