#pragma once
class Shader
{
public:
	unsigned int m_Id;

	Shader();
	Shader(const char* vertPath, const char* fragPath);
	~Shader();

	void useShader();

	void setUniformBool(const std::string &name, bool value) const;
	void setUniformInt(const std::string &name, int value) const;
	void setUniformFloat(const std::string &name, float value) const;
};

