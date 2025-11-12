import type { APIRoute } from 'astro'

export const prerender = false

export const POST: APIRoute = async ({ params }) => {
  const beatmapsetId = params.id
  if (!beatmapsetId) {
    return new Response(JSON.stringify({ error: 'Beatmapset ID is required' }), {
      status: 400,
      headers: { 'Content-Type': 'application/json' },
    })
  }

  try {
    // In a real implementation, you'd save to a database here
    // For now, we'll just return success since localStorage handles it client-side
    
    return new Response(
      JSON.stringify({
        success: true,
        beatmapsetId,
      }),
      {
        status: 200,
        headers: { 'Content-Type': 'application/json' },
      },
    )
  } catch (error) {
    console.error('Error tracking view:', error)
    return new Response(JSON.stringify({ error: 'Internal server error' }), {
      status: 500,
      headers: { 'Content-Type': 'application/json' },
    })
  }
}

