
namespace Aqua {
	__declspec(dllimport) void print(const char* message);
}

int main() {
	Aqua::print("Project setup works.");
	return 0;
}