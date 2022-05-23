# ProjectJumper
1. Hướng dẫn cài đặt:
- Copy link repository rồi nhập lệnh git clone + link để lấy file về máy để trong tệp X bất kì
- Trên codeblock, chọn File/Open/X/cbp/ProjectJumper.cbp để mở project
- Add tất cả các file trong tệp X/hnrsc vào project
- Chạy project (Máy cần có thư viên SDL2_image.h và SDL2_mixer.h)
2. Mô tả chung:
- Project là bản clone lại của game Geometry Dash nhưng cùi hơn :(
- Trò chơi thuộc thể loại phiêu lưu, vượt chướng ngại vật
- Có 2 chế độ chơi cơ bản là khối nhảy và tàu bay
- Vượt chướng ngại vật để qua màn chơi, người chơi phải chơi lại từ đầu nếu đâm vào chướng ngại.
3. Mô tả các chức năng
- Có Menu khởi động và menu chọn level
- ở chế độ khối, ấn hoặc giữ nút SPACE để nhảy
- ở chế độ tàu, giữ nút SPACE để tăng độ cao, thả nút để rơi xuống
- có nhạc nền và âm thanh hiệu ứng khi đâm vào chướng ngại
- Ấn ESC để tạm dừng game
- LINK YOUTUBE MINH HỌA :https://youtu.be/sXMF_CVa1J8
4. Các kỹ thuật lập trình đã sử dụng
- Cấu trúc tuần tự, rẽ nhánh, vòng lặp
- Thư viện vector
- Đọc thông tin từ tệp, tệp hình ảnh, tệp âm thanh
- Thư viện đồ họa, thư viện SDL2_image.h, thư viện SDL2_mixer.h
- Tách file
5. Kết luận, hướng phát triên, điều tâm đắc
- KL: Project có thể chạy được bình thường, đúng ý tưởng
- HPT: 
+ Thêm level, thêm các vật thể (bệ phóng, đổi chiều trọng lực, ...), thêm chế độ chơi
+ Nâng cấp code để chương trình chạy nhanh hơn, giảm lag, thu gọn code, tối ưu va chạm với vật thể
+ Sửa lỗi mà khi viết chương trình chưa phát hiện ra
- Điều tâm đắc: 
+ Đây là project dầu tiên nên phải bỏ ra nhiều thời gian để nghiên cứu, thử nghiệm -> để lại rất nhiều kinh nghiệm quý báu cho những project tương lai
+ Tự code lại được tựa game mà bản thân đã chơi và yêu thích
