#pragma once

#include "Lumina/Renderer/Renderer.h"
#include "Lumina/Renderer/Buffer.h"
#include "Lumina/Renderer/VertexArray.h"
#include "Lumina/Renderer/ShaderProgram.h"

#include "Lumina/Renderer/OrthographicCamera.h"

#include "../Core/Base.h"
#include "../Core/Camera.h"

#include "imgui.h"

namespace Tiles
{
	class ViewportPanel
	{
	public:
		ViewportPanel();
		void Render();

		// Mouse events
		void HandleMouseInput(); 

		// Helper
		bool IsMouseInViewport(const ImVec2& mousePos, const ImVec2& windowPos, const ImVec2& windowSize);
	private:
		Lumina::Renderer m_Renderer;
		Shared<Lumina::VertexArray> m_Grid;
		Shared<Lumina::ShaderProgram> m_GridShader;

		Camera m_Camera;

		// Mouse interaction state
		bool m_IsMiddleMouseDown = false;
		glm::vec2 m_LastMousePos = { 0.0f, 0.0f };
		glm::vec2 m_CameraPosition = { 0.0f, 0.0f };
		
		glm::vec2 m_AnchorePos = { 0.0f, 0.0f };

		float m_Sensitivity = 0.05f; // Adjust this value for the desired speed reduction
	};
}