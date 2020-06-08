#include <iostream>
#include <string>
#include <array>
#include <vector>

struct alignas(16) PacketMsg ///< LiDAR single packet message
{
  double timestamp = 0.0;	///< Time stamp
  std::string frame_id = ""; ///< Frame ID
  std::array<uint8_t, 1248> packet{}; ///< Data
};

struct alignas(16) ScanMsg
{
  double timestamp = 0.0;
  uint32_t seq = 0;
  std::string parent_frame_id = ""; ///< which coordinate the message is in
  std::string frame_id = "";
  std::vector<PacketMsg> packets; ///< A vector which store a scan of packets (the size of the vector is not fix)
};

struct s11
{
    int i;
    alignas(16) char s;
};
 
struct s12
{
    int i;
    typedef std::vector<int> PointCloud;
    alignas(16) char s;
};


int main (int argc, char** argv)
{
  std::cout << "sizeof s11: " << sizeof(s11) << std::endl;
  std::string frame_id = "sdrfghjqaerhgaelirgalkjherbglkjahebrglihaerigbaeljhrgbljaherbgj,haerbglkjhaerbgljhaebrgljhaebrglkjhbaerljhgbaerljhgbaljehrbljhaerbgljhaerbgljheargbbjh";
  std::cout << "sizeof s12		" << sizeof(s12) << std::endl;
  std::cout << "alignof std::vector<PacketMsg>	" << alignof(std::vector<PacketMsg>) << std::endl;

  PacketMsg pm;

  std::cout << "double start:   " << &pm.timestamp << std::endl;
  std::cout << "frame_id start: " << &pm.frame_id << std::endl;
  std::cout << "packet start:   " << &pm.packet << std::endl;  
}